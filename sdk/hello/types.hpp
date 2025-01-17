////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <chrono>
#include <yq/math/glm.hpp>  // temporary

struct Vertex {
    glm::vec2   position;
    glm::vec3   color;
};

struct Warp {
    float   amt = 0;
};


struct Vertex2 {
    glm::vec2   position;
    glm::vec2   uv;
};


using timepoint_t   = std::chrono::time_point<std::chrono::steady_clock>;
