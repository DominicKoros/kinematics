//#pragma once 
//
//#include "CompileShader.h"
//#include "InputLayout.h"
//
//void InitializeShader(ID3D11Device* device, ID3D11DeviceContext* deviceContext, const char* vsFilename, const char* psFilename, const char* gsFilename, const char* hsFilename, const char* dsFilename, const char* csFilename, const D3D11_INPUT_ELEMENT_DESC* layout, UINT numElements, ID3D11VertexShader** vertexShader, ID3D11PixelShader** pixelShader, ID3D11GeometryShader** geometryShader, ID3D11HullShader** hullShader, ID3D11DomainShader** domainShader, ID3D11ComputeShader** computeShader, ID3D11InputLayout** inputLayout)
//{
//	CompileShaderFromFile(device, vsFilename, "vs_5_0", vertexShader);
//	CompileShaderFromFile(device, psFilename, "ps_5_0", pixelShader);
//	if (gsFilename != nullptr)
//	{
//		CompileShaderFromFile(device, gsFilename, "gs_5_0", geometryShader);
//	}
//	if (hsFilename != nullptr)
//	{
//		CompileShaderFromFile(device, hsFilename, "hs_5_0", hullShader);
//	}
//	if (dsFilename != nullptr)
//	{
//		CompileShaderFromFile(device, dsFilename, "ds_5_0", domainShader);
//	}
//	if (csFilename != nullptr)
//	{
//		CompileShaderFromFile(device, csFilename, "cs_5_0", computeShader);
//	}
//	CreateInputLayout(device, deviceContext, vertexShader, layout, numElements, inputLayout);
//}