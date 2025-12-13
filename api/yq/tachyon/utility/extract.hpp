////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/glm.hpp>

namespace yq::tachyon {
    constexpr float x1_uint8(uint8_t v) { return (float) v; }
    constexpr float x1_uint16(uint16_t v) { return (float) v; }
    constexpr float x1_uint32(uint32_t v) { return (float) v; }
    constexpr float x1_uint64(uint64_t v) { return (float) v; }

    constexpr float x1_double(double v) { return (float) v; }
    constexpr float x1_float(float v) { return v; }
    constexpr float x1_int8(int8_t v) { return (float) v; }
    constexpr float x1_int16(int16_t v) { return (float) v; }
    constexpr float x1_int32(int32_t v) { return (float) v; }
    constexpr float x1_int64(int64_t v) { return (float) v; }
    
    constexpr float x1_vec2d(const glm::dvec2& v) { return v.x; }
    constexpr float x1_vec3d(const glm::dvec3& v) { return v.x; }
    constexpr float x1_vec4d(const glm::dvec4& v) { return v.x; }

    constexpr float x1_vec2f(const glm::vec2& v) { return v.x; }
    constexpr float x1_vec3f(const glm::vec3& v) { return v.x; }
    constexpr float x1_vec4f(const glm::vec4& v) { return v.x; }

    constexpr float x1_vec2i8(const glm::i8vec2& v) { return v.x; }
    constexpr float x1_vec3i8(const glm::i8vec3& v) { return v.x; }
    constexpr float x1_vec4i8(const glm::i8vec4& v) { return v.x; }

    constexpr float x1_vec2i16(const glm::i16vec2& v) { return v.x; }
    constexpr float x1_vec3i16(const glm::i16vec3& v) { return v.x; }
    constexpr float x1_vec4i16(const glm::i16vec4& v) { return v.x; }

    constexpr float x1_vec2u8(const glm::u8vec2& v) { return v.x; }
    constexpr float x1_vec3u8(const glm::u8vec3& v) { return v.x; }
    constexpr float x1_vec4u8(const glm::u8vec4& v) { return v.x; }

    constexpr float x1_vec2u16(const glm::u16vec2& v) { return v.x; }
    constexpr float x1_vec3u16(const glm::u16vec3& v) { return v.x; }
    constexpr float x1_vec4u16(const glm::u16vec4& v) { return v.x; }

    constexpr float x1_vec2u32(const glm::u32vec2& v) { return v.x; }
    constexpr float x1_vec3u32(const glm::u32vec3& v) { return v.x; }
    constexpr float x1_vec4u32(const glm::u32vec4& v) { return v.x; }

    constexpr float x1_vec2i32(const glm::i32vec2& v) { return v.x; }
    constexpr float x1_vec3i32(const glm::i32vec3& v) { return v.x; }
    constexpr float x1_vec4i32(const glm::i32vec4& v) { return v.x; }

    constexpr float x2_vec2d(const glm::dvec2& v) { return v.y; }
    constexpr float x2_vec3d(const glm::dvec3& v) { return v.y; }
    constexpr float x2_vec4d(const glm::dvec4& v) { return v.y; }

    constexpr float x2_vec2f(const glm::vec2& v) { return v.y; }
    constexpr float x2_vec3f(const glm::vec3& v) { return v.y; }
    constexpr float x2_vec4f(const glm::vec4& v) { return v.y; }

    constexpr float x2_vec2i8(const glm::i8vec2& v) { return v.y; }
    constexpr float x2_vec3i8(const glm::i8vec3& v) { return v.y; }
    constexpr float x2_vec4i8(const glm::i8vec4& v) { return v.y; }

    constexpr float x2_vec2i16(const glm::i16vec2& v) { return v.y; }
    constexpr float x2_vec3i16(const glm::i16vec3& v) { return v.y; }
    constexpr float x2_vec4i16(const glm::i16vec4& v) { return v.y; }

    constexpr float x2_vec2u8(const glm::u8vec2& v) { return v.y; }
    constexpr float x2_vec3u8(const glm::u8vec3& v) { return v.y; }
    constexpr float x2_vec4u8(const glm::u8vec4& v) { return v.y; }

    constexpr float x2_vec2u16(const glm::u16vec2& v) { return v.y; }
    constexpr float x2_vec3u16(const glm::u16vec3& v) { return v.y; }
    constexpr float x2_vec4u16(const glm::u16vec4& v) { return v.y; }

    constexpr float x2_vec2u32(const glm::u32vec2& v) { return v.y; }
    constexpr float x2_vec3u32(const glm::u32vec3& v) { return v.y; }
    constexpr float x2_vec4u32(const glm::u32vec4& v) { return v.y; }

    constexpr float x3_vec3d(const glm::dvec3& v) { return v.z; }
    constexpr float x3_vec4d(const glm::dvec4& v) { return v.z; }

    constexpr float x3_vec3f(const glm::vec3& v) { return v.z; }
    constexpr float x3_vec4f(const glm::vec4& v) { return v.z; }

    constexpr float x3_vec3i8(const glm::i8vec3& v) { return v.z; }
    constexpr float x3_vec4i8(const glm::i8vec4& v) { return v.z; }

    constexpr float x3_vec3i16(const glm::i16vec3& v) { return v.z; }
    constexpr float x3_vec4i16(const glm::i16vec4& v) { return v.z; }

    constexpr float x3_vec3u8(const glm::u8vec3& v) { return v.z; }
    constexpr float x3_vec4u8(const glm::u8vec4& v) { return v.z; }

    constexpr float x3_vec3u16(const glm::u16vec3& v) { return v.z; }
    constexpr float x3_vec4u16(const glm::u16vec4& v) { return v.z; }

    constexpr float x3_vec3u32(const glm::u32vec3& v) { return v.z; }
    constexpr float x3_vec4u32(const glm::u32vec4& v) { return v.z; }

    constexpr float x4_vec4d(const glm::dvec4& v) { return v.w; }
    constexpr float x4_vec4f(const glm::vec4& v) { return v.w; }
    constexpr float x4_vec4i8(const glm::i8vec4& v) { return v.w; }
    constexpr float x4_vec4i16(const glm::i16vec4& v) { return v.w; }
    constexpr float x4_vec4u8(const glm::u8vec4& v) { return v.w; }
    constexpr float x4_vec4u16(const glm::u16vec4& v) { return v.w; }
    constexpr float x4_vec4u32(const glm::u32vec4& v) { return v.w; }
}
