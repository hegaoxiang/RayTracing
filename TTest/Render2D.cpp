#include "Render2D.h"
#include<list>
#include<vector>
using namespace std;

void Render2D::DrawLine(int x1, int y1, int x2, int y2)
{
	
	int dx = x2 - x1;
	int dy = y2 - y1;

	int flagX = (dx > 0) ? 1 : -1;
	int flagY = (dy > 0) ? 1 : -1;

	dx *= flagX;
	dy *= flagY;

	int step = (dx > dy) ? dx : dy;

	int e = 0;// e = d * dx
	int x = 0, y = 0;// 将直线平移到x1，y1为原点，通过flagX和flagY解决非第一象限的直线问题

	if (dx > dy)
	{
		for (int i = 0; i < step; i++)
		{
			
			SetPixel(x * flagX + x1, y * flagY + y1);
			
			x++;

			e = e + dy;

			if (2 * e > dx)
			{
				e -= dx;
				y++;
			}
		}
	}
	else
	{
		for (int i = 0; i < step; i++)
		{
			
			SetPixel(x * flagX + x1, y * flagY + y1);
			y++;

			e = e + dx;

			if (2 * e > dy)
			{
				e -= dy;
				x++;
			}
		}
	}/*
	int row_distance = abs(row0 - row1);
	int col_distance = abs(col0 - col1);
	if (row_distance == 0 && col_distance == 0) {
		SetPixel(col0, row0);
	}
	else if (row_distance > col_distance) {
		int row;
		if (row0 > row1) {
			int_swap(&row0, &row1);
			int_swap(&col0, &col1);
		}
		for (row = row0; row <= row1; row++) {
			float t = (float)(row - row0) / (float)row_distance;
			int col = int_lerp(col0, col1, t);
			draw_point(framebuffer, color, row, col);
		}
	}
	else {
		int col;
		if (col0 > col1) {
			int_swap(&col0, &col1);
			int_swap(&row0, &row1);
		}
		for (col = col0; col <= col1; col++) {
			float t = (float)(col - col0) / (float)col_distance;
			int row = int_lerp(row0, row1, t);
			draw_point(framebuffer, color, row, col);
		}
	}*/
}

void Render2D::DrawCircle(int x, int y, int radius)
{
	int x0 = 0;
	int y0 = radius;

	int d = 1 - radius;
	while (x0 <= y0)
	{
		SetPixel(x + x0, y + y0);
		SetPixel(x + x0, y + -y0);
		SetPixel(x + -x0, y + y0);
		SetPixel(x + -x0, y + -y0);
		SetPixel(x + y0, y + x0);
		SetPixel(x + y0, y + -x0);
		SetPixel(x + -y0, y + x0);
		SetPixel(x + -y0, y + -x0);
		
		if (d < 0)
			d += 2 * x0 + 3;
		else
		{
			d += 2 * (x0 - y0) + 5;
			y0--;
		}
		x0++;
	}
}

void Render2D::DrawTriangle(int col0, int row0,  int col1, int row1, int col2 ,int row2 )
{
	assert(row0 >= 0 && row0 < m_pFrameBuf->m_height);
	assert(row1 >= 0 && row1 < m_pFrameBuf->m_height);
	assert(row2 >= 0 && row2 < m_pFrameBuf->m_height);
	assert(col0 >= 0 && col0 < m_pFrameBuf->m_width);
	assert(col1 >= 0 && col1 < m_pFrameBuf->m_width);
	assert(col2 >= 0 && col2 < m_pFrameBuf->m_width);
	DrawLine( col0,row0, col1, row1);
	DrawLine(col1, row1, col2, row2);
	DrawLine(col2, row2, col0, row0);
	typedef struct Point
	{
		int x;
		int y;
	}Point;
	//斜率
	auto GetK = [](const Point& p1, const Point& p2) {
		int dy = p1.y - p2.y;
		int dx = p1.x - p2.x;
		return  static_cast<float>(dx) / static_cast<float>(dy); 
	};
	typedef struct EdgeNode
	{
		float xLow;
		int yHigh;
		float k;
		EdgeNode* next;
	}EdgeNode;

	vector<Point> points;
	points.push_back(Point{ col0,row0 });
	points.push_back(Point{ col1,row1 });
	points.push_back(Point{ col2,row2 });

	

	// 得到Ymin和Ymax
	int minY = 2000;
	int maxY = 0;
	for (auto item : points)
	{
		minY = (item.y >= minY) ? minY : item.y;
		maxY = (item.y <= maxY) ? maxY : item.y;
	}
	int edgeTableSize = maxY - minY + 1;

	vector<EdgeNode> edgeTable(edgeTableSize);
	
	

	for (auto iter = points.begin(); iter != points.end(); ++iter)
	{
		EdgeNode* temp = new EdgeNode();
		Point& p1 = *iter;
		Point& p2 = (iter != points.end() - 1) ? (*(iter + 1)) : (*points.begin());

		EdgeNode* currentNode;
		// 添加顶点信息
		if (p1.y > p2.y)
		{
			currentNode = &edgeTable[p2.y - minY];

			temp->xLow = p2.x;
			temp->yHigh = p1.y - 1;
			temp->k = GetK(p1,p2);
			temp->next = nullptr;
		}
		else
		{
			currentNode = &edgeTable[p1.y - minY];

			temp->xLow = p1.x;
			temp->yHigh = p2.y - 1;
			temp->k = GetK(p1, p2);
			temp->next = nullptr;
		}
		if (currentNode->next == NULL)
		{
			//currentNode->xLow = 1;
			currentNode->next = temp;
		}
		else
		{
			auto nextNode = currentNode->next;
			// join and sort
			while (nextNode != NULL)
			{
				if (temp->xLow < nextNode->xLow || (temp->xLow == nextNode->xLow && temp->k < nextNode->k))
				{
					// 把新点加入到nextNode前
					currentNode->next = temp;
					temp->next = nextNode;
					break;
				}
				else
				{
					currentNode = nextNode;
					nextNode = nextNode->next;
				}
			}
			if (temp->next == NULL)
			{
				currentNode->next = temp;
			}
		}
	};

	list<EdgeNode> AET;

	for (int i = 0; i < edgeTableSize; i++)
	{
		int currentY = i + minY;
		auto currentNode = edgeTable[i].next;
		// 加入新边
		while (currentNode != nullptr)
		{
			auto& ae = *currentNode;
			// 插入新边
			auto iter = AET.begin();
			for (; iter != AET.end(); ++iter)
			{
				if (iter->xLow > ae.xLow)
				{
					if (iter == AET.begin())// 插入第一个
					{
						AET.push_front(ae);
					}
					else
					{

						AET.insert(iter, ae);

					}
					break;
				}
			}

			if (iter == AET.end())
			{
				AET.push_back(ae);
			}
			currentNode = currentNode->next;
		}
		// 遍历AET，上色后处理删除事件
		for (auto iter = AET.begin(); iter != AET.end(); ++iter, ++iter)
		{
			if (++iter == AET.end())
			{
				break;
			}
			--iter;
			// 上色
			auto iter_back = iter;

			iter_back++;

			auto& x1 = (*iter);
			auto& x2 = (*iter_back);

			for (int x = x1.xLow + 0.5; x <= x2.xLow; x++)
			{
				SetPixel(x, currentY);
			}
			// 处理删除

			x1.xLow += x1.k;
			x2.xLow += x2.k;
		}

		for (auto iter = AET.begin(); iter != AET.end(); )
		{

			if (iter->yHigh == currentY)
			{
				iter = AET.erase(iter);
			}
			else
			{
				iter++;
			}
		}

	}
	
}

void Render2D::SetFrameBuf(const FrameBuffer& frameBuf)
{
	m_pFrameBuf = new FrameBuffer(frameBuf);
}

void Render2D::SetPixel(int x, int y,Vec4 color)
{
	m_pFrameBuf->SetPixel(y, x, color);
}

void Render2D::SetPixel(int x, int y)
{
	SetPixel(x, y, Vec4{ 255,1,1,0 });
}

