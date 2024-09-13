#pragma once

#include <vector>
#include <DirectXMath.h>

struct Vertex
{
    DirectX::XMFLOAT3 Position;
    DirectX::XMFLOAT3 Normal;
    DirectX::XMFLOAT2 TexCoord;
};

void CreateSphere(float radius, unsigned int latitudeSegments, unsigned int longitudeSegments, std::vector<Vertex>& vertices, std::vector<unsigned int>& indices)
{
    using namespace DirectX;

    vertices.clear();
    indices.clear();

    // Generate vertices
    for (unsigned int lat = 0; lat <= latitudeSegments; ++lat)
    {
        float theta = lat * XM_PI / latitudeSegments;
        float sinTheta = sinf(theta);
        float cosTheta = cosf(theta);

        for (unsigned int lon = 0; lon <= longitudeSegments; ++lon)
        {
            float phi = lon * XM_2PI / longitudeSegments;
            float sinPhi = sinf(phi);
            float cosPhi = cosf(phi);

            XMFLOAT3 position(
                radius * sinTheta * cosPhi,
                radius * cosTheta,
                radius * sinTheta * sinPhi
            );

            XMFLOAT3 normal;
            XMStoreFloat3(&normal, XMVector3Normalize(XMLoadFloat3(&position)));

            XMFLOAT2 texCoord(
                static_cast<float>(lon) / longitudeSegments,
                static_cast<float>(lat) / latitudeSegments
            );

            vertices.push_back({ position, normal, texCoord });
        }
    }

    // Generate indices
    for (unsigned int lat = 0; lat < latitudeSegments; ++lat)
    {
        for (unsigned int lon = 0; lon < longitudeSegments; ++lon)
        {
            unsigned int first = (lat * (longitudeSegments + 1)) + lon;
            unsigned int second = first + longitudeSegments + 1;

            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }
}
