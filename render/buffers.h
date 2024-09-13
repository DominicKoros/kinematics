#pragma once
#include <D3D11.h>
#include <vector>
#include "sphere/sphereMesh.h"

ID3D11Buffer* vertexBuffer = nullptr;
ID3D11Buffer* indexBuffer = nullptr;

void Buffers(ID3D11Device* device, ID3D11DeviceContext* context, const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
{
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(Vertex) * vertices.size();
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = vertices.data();

	device->CreateBuffer(&bufferDesc, &initData, &vertexBuffer);

	bufferDesc.ByteWidth = sizeof(unsigned int) * indices.size();
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;

	initData.pSysMem = indices.data();

	device->CreateBuffer(&bufferDesc, &initData, &indexBuffer);
}