#pragma once
#include<random>
#include<DirectXMath.h>
using namespace DirectX;
using DirectX::XMLoadFloat3;
using DirectX::XMStoreFloat3;
using DirectX::XMVector3Normalize;
using DirectX::XMFLOAT3;
using DirectX::XMVECTOR;
typedef DirectX::XMFLOAT3 Vector3;
typedef DirectX::XMVECTOR Vector;
typedef DirectX::XMFLOAT3 Point;
typedef DirectX::XMFLOAT3 Direction;
typedef Vector3 RGB;

XMFLOAT3 mul(XMFLOAT3 v1, float t);

XMFLOAT3 puls(XMFLOAT3 v1, XMFLOAT3 v2);

XMFLOAT3 sub(XMFLOAT3 vl, XMFLOAT3 vr);

float dot(XMFLOAT3 v1, XMFLOAT3 v2);

float length(XMFLOAT3 p);

XMFLOAT3 unit(XMFLOAT3 v);
float drand();
