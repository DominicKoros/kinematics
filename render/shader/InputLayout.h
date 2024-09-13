#pragma once
#include <D3D11.h>
#include <cstddef>

void CreateInputLayout(
    ID3D11Device* device,
    ID3D11DeviceContext* context,
    ID3DBlob* vertexShaderBlob,
    ID3D11InputLayout** inputLayout
)
{
    D3D11_INPUT_ELEMENT_DESC layoutDesc[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, offsetof(Vertex, Position), D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, offsetof(Vertex, Normal),   D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0, offsetof(Vertex, TexCoord), D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    HRESULT hr = device->CreateInputLayout(
        layoutDesc,
        _countof(layoutDesc),
        vertexShaderBlob->GetBufferPointer(),
        vertexShaderBlob->GetBufferSize(),
        inputLayout
    );

    if (FAILED(hr))
    {
        // Handle error
    }

    // Set the input layout
    context->IASetInputLayout(*inputLayout);
}
