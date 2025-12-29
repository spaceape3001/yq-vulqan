////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>

#include <yq/math/glm.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <yq/typedef/quaternion3.hpp>
#include <yq/typedef/range.hpp>
#include <yq/typedef/rectangle2.hpp>
#include <yq/typedef/rgb.hpp>
#include <yq/typedef/rgba.hpp>
#include <yq/typedef/size2.hpp>
#include <yq/typedef/size3.hpp>
#include <yq/typedef/size4.hpp>
#include <yq/typedef/tensor44.hpp>
#include <yq/typedef/url.hpp>
#include <yq/typedef/uv.hpp>
#include <yq/typedef/uvw.hpp>
#include <yq/typedef/vector1.hpp>
#include <yq/typedef/vector2.hpp>
#include <yq/typedef/vector3.hpp>
#include <yq/typedef/vector4.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/unit/SCALED.hpp>

namespace yq {
    class Any;
}

namespace yq::tachyon::im {
    void    text(bool);
    void    text(double);
    void    text(float);
    void    text(int8_t);
    void    text(int16_t);
    void    text(int32_t);
    void    text(int64_t);
    void    text(uint8_t);
    void    text(uint16_t);
    void    text(uint32_t);
    void    text(uint64_t);
    
    void    text(std::string_view);
    void    text(const char*);
    void    text(const std::string&);
    void    text(const std::filesystem::path&);
    
        // others to be added as necessary
    
    void    text(const Any&);
    void    text(const Quaternion3D&);
    void    text(const Quaternion3F&);
    void    text(const Rectangle2D&);
    void    text(const Rectangle2F&);
    void    text(const RGB3F&);
    void    text(const RGB3U8&);
    void    text(const RGBA4F&);
    void    text(const RGBA4U8&);
    void    text(const Size2D&);
    void    text(const Size2F&);
    void    text(const Size2I&);
    void    text(const Size2U&);
    void    text(const Size3D&);
    void    text(const Size3F&);
    void    text(const Size3I&);
    void    text(const Size3U&);
    void    text(const Size4D&);
    void    text(const Size4F&);
    void    text(const Size4I&);
    void    text(const Size4U&);
    void    text(const Tensor44D&);
    void    text(const Url&);
    void    text(const UrlView&);
    void    text(const UV2D&);
    void    text(const UV2F&);
    void    text(const UVW3D&);
    void    text(const UVW3F&);
    void    text(const Vector1D&);
    void    text(const Vector1F&);
    void    text(const Vector1U&);
    void    text(const Vector2D&);
    void    text(const Vector2F&);
    void    text(const Vector2U&);
    void    text(const Vector3D&);
    void    text(const Vector3F&);
    void    text(const Vector3U&);
    void    text(const Vector4D&);
    void    text(const Vector4F&);
    void    text(const Vector4U&);

    void    text(const glm::mat4&);
    void    text(const glm::dmat4&);
    
    template <typename T>
    void    text(const ID<T>& v)
    {
        text(v.id);
    }
    
    template <typename T, typename DIM>
    void    text(const MKS<T,DIM>& v)
    {
        text(v.value);
    }

    template <typename T, typename DIM, double K>
    void    text(const SCALED<T,DIM,K>& v)
    {
        text(v.value);
    }
}
