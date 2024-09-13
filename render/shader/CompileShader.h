#pragma once
#pragma comment(lib, "D3DCompiler.lib")

#include <iostream>
#include <string>
#include <d3dcompiler.h>
#include <d3d11.h>
#include "InputLayout.h"


HRESULT CompileShaderFromFile(ID3D11Device* device, ID3D11DeviceContext* deviceContext, ID3D11InputLayout** inputLayout) {

    // Assume device is a valid ID3D11Device*

    UINT compileFlags = 0;
#ifdef _DEBUG
    compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
    compileFlags = D3DCOMPILE_OPTIMIZATION_LEVEL3;
#endif

    // Compile Vertex Shader
    ID3DBlob* vertexShaderBlob = nullptr;
    ID3DBlob* errorBlob = nullptr;

    HRESULT hr = D3DCompileFromFile(
        L"SphereVS.hlsl",
        nullptr,
        D3D_COMPILE_STANDARD_FILE_INCLUDE,
        "main",
        "vs_5_0",
        compileFlags,
        0,
        &vertexShaderBlob,
        &errorBlob
    );

    if (FAILED(hr))
    {
        if (errorBlob)
        {
            std::cerr << "Vertex Shader Compilation Error: " << (char*)errorBlob->GetBufferPointer() << std::endl;
            errorBlob->Release();
        }
        else
        {
            std::cerr << "Unknown error compiling vertex shader." << std::endl;
        }
        // Clean up and exit or handle error
        return hr;
    }

    // Create Vertex Shader
    ID3D11VertexShader* vertexShader = nullptr;
    hr = device->CreateVertexShader(
        vertexShaderBlob->GetBufferPointer(),
        vertexShaderBlob->GetBufferSize(),
        nullptr,
        &vertexShader
    );

    if (FAILED(hr))
    {
        std::cerr << "Failed to create vertex shader." << std::endl;
        vertexShaderBlob->Release();
        // Handle error
        return hr;
    }

    // Compile Pixel Shader
    ID3DBlob* pixelShaderBlob = nullptr;
    hr = D3DCompileFromFile(
        L"SpherePS.hlsl",
        nullptr,
        D3D_COMPILE_STANDARD_FILE_INCLUDE,
        "main",
        "ps_5_0",
        compileFlags,
        0,
        &pixelShaderBlob,
        &errorBlob
    );

    if (FAILED(hr))
    {
        if (errorBlob)
        {
            std::cerr << "Pixel Shader Compilation Error: " << (char*)errorBlob->GetBufferPointer() << std::endl;
            errorBlob->Release();
        }
        else
        {
            std::cerr << "Unknown error compiling pixel shader." << std::endl;
        }
        // Clean up and exit or handle error
        return hr;
    }

    // Create Pixel Shader
    ID3D11PixelShader* pixelShader = nullptr;
    hr = device->CreatePixelShader(
        pixelShaderBlob->GetBufferPointer(),
        pixelShaderBlob->GetBufferSize(),
        nullptr,
        &pixelShader
    );

    if (FAILED(hr))
    {
        std::cerr << "Failed to create pixel shader." << std::endl;
        pixelShaderBlob->Release();
        // Handle error
        return hr;
    }

    CreateInputLayout(device, deviceContext, vertexShaderBlob, inputLayout);

    // Release shader blobs
    vertexShaderBlob->Release();
    pixelShaderBlob->Release();
    return hr;
}