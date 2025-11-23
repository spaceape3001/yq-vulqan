////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <memory>

//  NOTE, the library being referenced has its own license, so including that here

//
// Header-only tiny glTF 2.0 loader and serializer.
//
//
// The MIT License (MIT)
//
// Copyright (c) 2015 - Present Syoyo Fujita, Aurélien Chatelain and many
// contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

// Version: - v2.9.*
// See https://github.com/syoyo/tinygltf/releases for release history.
//
// Tiny glTF loader is using following third party libraries:
//
//  - jsonhpp: C++ JSON library.
//  - base64: base64 decode/encode library.
//  - stb_image: Image loading library.
//

namespace tinygltf {
    struct Accessor;
    struct Animation;
    struct AnimationChannel;
    struct AnimationSampler;
    struct Asset;
    struct AudioEmitter;
    struct AudioSource;
    struct Buffer;
    struct BufferView;
    struct Camera;
    struct Image;
    struct Light;
    struct Material;
    struct Mesh;
    struct Model;
    struct Node;
    struct NormalTextureInfo;
    struct OcclusionTextureInfo;
    struct OrthographicCamera;
    struct PbrMetallicRoughness;
    struct PerspectiveCamera;
    struct PositionalEmitter;
    struct Primitive;
    struct Sampler;
    struct Scene;
    struct Skin;
    struct Spotlight;
    struct Texture;
    struct TextureInfo;
    
    using ModelSPtr = std::shared_ptr<Model>;
    using ModelSCPtr = std::shared_ptr<const Model>;
}
