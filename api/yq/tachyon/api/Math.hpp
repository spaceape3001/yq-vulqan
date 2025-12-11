////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/keywords.hpp>
#include <yq/typedef/quaternion3.hpp>
#include <yq/typedef/tensor33.hpp>
#include <yq/typedef/tensor44.hpp>
#include <yq/typedef/vector3.hpp>
#include <initializer_list>

namespace yq::tachyon {
    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D&, identity_k, const Vector3D&);
    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D&, const Quaternion3D&);
    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D&, const Quaternion3D&, const Vector3D&);
    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D&, const Tensor33D&);
    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D&, const Tensor33D&, const Vector3D&);
}

