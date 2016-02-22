//
// Copyright 2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// texture_format_table:
//   Queries for full textureFormat information based on internalFormat
//

#ifndef LIBANGLE_RENDERER_D3D_D3D11_TEXTUREFORMATTABLE_H_
#define LIBANGLE_RENDERER_D3D_D3D11_TEXTUREFORMATTABLE_H_

#include <map>

#include "common/platform.h"
#include "libANGLE/renderer/d3d/formatutilsD3D.h"
#include "libANGLE/renderer/d3d/d3d11/Renderer11.h"

namespace rx
{

namespace d3d11
{

struct LoadImageFunctionInfo
{
    LoadImageFunctionInfo() : loadFunction(nullptr), requiresConversion(false) {}
    LoadImageFunctionInfo(LoadImageFunction loadFunction, bool requiresConversion)
        : loadFunction(loadFunction), requiresConversion(requiresConversion)
    {
    }

    LoadImageFunction loadFunction;
    bool requiresConversion;
};

struct DXGIFormatSet
{
    DXGIFormatSet();
    DXGIFormatSet(const DXGIFormatSet &) = default;
    DXGIFormatSet &operator=(const DXGIFormatSet &) = default;

    DXGI_FORMAT texFormat;
    DXGI_FORMAT srvFormat;
    DXGI_FORMAT rtvFormat;
    DXGI_FORMAT dsvFormat;
};

struct TextureFormat : public angle::NonCopyable
{
    TextureFormat(GLenum internalFormat,
                  DXGI_FORMAT texFormat,
                  DXGI_FORMAT srvFormat,
                  DXGI_FORMAT rtvFormat,
                  DXGI_FORMAT dsvFormat,
                  InitializeTextureDataFunction internalFormatInitializer);

    DXGIFormatSet formatSet;
    DXGIFormatSet swizzleFormatSet;

    InitializeTextureDataFunction dataInitializerFunction;
    typedef std::map<GLenum, LoadImageFunctionInfo> LoadFunctionMap;

    LoadFunctionMap loadFunctions;
};

const TextureFormat &GetTextureFormatInfo(GLenum internalformat,
                                          const Renderer11DeviceCaps &renderer11DeviceCaps);

}  // namespace d3d11

}  // namespace rx

#endif  // LIBANGLE_RENDERER_D3D_D3D11_TEXTUREFORMATTABLE_H_
