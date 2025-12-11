////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Math.hpp"
#include <yq/tensor/Tensor33.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D& pos, identity_k, const Vector3D& scale)
    {
        calculate_transform_matrix(l2d, p_d2l, pos, diagonal(scale));
    }

    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D&pos, const Quaternion3D&T)
    {
        calculate_transform_matrix(l2d, p_d2l, pos, tensor(T));
    }
    
    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D&pos, const Quaternion3D&T, const Vector3D&scale)
    {
        calculate_transform_matrix(l2d, p_d2l, pos, tensor(T), scale);
    }
    
    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D&pos, const Tensor33D&T)
    {
        l2d = Tensor44D(
            T.xx, T.xy, T.xz, pos.x,
            T.yx, T.yy, T.yz, pos.y,
            T.zx, T.zy, T.zz, pos.z,
            0., 0., 0., 1.
        );
        
        if(p_d2l){
            Tensor33D   T2   = inverse(T);
            Vector3D    pos2 = T2 * pos;
            
            *p_d2l = Tensor44D(
                T2.xx, T2.xy, T2.xz, -pos2.x,
                T2.yx, T2.yy, T2.yz, -pos2.y,
                T2.zx, T2.zy, T2.zz, -pos2.z,
                0., 0., 0., 1.
            );
        }
    }
    
    void    calculate_transform_matrix(Tensor44D& l2d, Tensor44D* p_d2l, const Vector3D&pos, const Tensor33D&T, const Vector3D&scale)
    {
        calculate_transform_matrix(l2d, p_d2l, pos, T*diagonal(scale));
    }
}

