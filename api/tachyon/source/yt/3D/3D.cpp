////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/3D/3D.hpp>
#include <yt/3D/3DData.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    ③Data::③Data()
    {
    }
    
    ③Data::~③Data()
    {
    }

    ③Snap::③Snap()
    {
    }
    
    ③Snap::~③Snap()
    {
    }
    

    ③::③()
    {
    }
    
    ③::~③()
    {
    }

    Tensor44D   ③::local2domain() const
    {
        return IDENTITY;
    }
    
    Tensor44D   ③::domain2local() const
    {
        return IDENTITY;
    }

    void    ③::finalize(③Data&d) const
    {
        И::finalize(d);
    }

    void    ③::snap(③Snap&sn) const
    {
        И::snap(sn);
    }
}

