////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/ASize3.hpp>
#include <ya/commands/spatial/AddSize3.hpp>
#include <ya/commands/spatial/AddSizeX.hpp>
#include <ya/commands/spatial/AddSizeY.hpp>
#include <ya/commands/spatial/AddSizeZ.hpp>
#include <ya/commands/spatial/MultiplySize.hpp>
#include <ya/commands/spatial/MultiplySize3.hpp>
#include <ya/commands/spatial/MultiplySizeX.hpp>
#include <ya/commands/spatial/MultiplySizeY.hpp>
#include <ya/commands/spatial/MultiplySizeZ.hpp>
#include <ya/commands/spatial/SetSize3.hpp>
#include <ya/commands/spatial/SetSizeX.hpp>
#include <ya/commands/spatial/SetSizeY.hpp>
#include <ya/commands/spatial/SetSizeZ.hpp>
#include <ya/events/spatial/Size3Event.hpp>


namespace yq::tachyon {
    ASize³::ASize³()
    {
    }
    
    ASize³::~ASize³()
    {
    }

    void        ASize³::size(set_k, const Size3D& sz) 
    {
        m_size  =    sz;
        send(new Size³Event({.source=typed()}, sz));
    }
    
    void        ASize³::size(set_k, x_k, double v) 
    {
        size(SET, Size3D(v, m_size.y, m_size.z));
    }
    
    void        ASize³::size(set_k, y_k, double v) 
    {
        size(SET, Size3D(m_size.x,v, m_size.z));
    }
    
    void        ASize³::size(set_k, z_k, double v) 
    {
        size(SET, Size3D(m_size.x, m_size.y, v));
    }
    
    void        ASize³::size(add_k, const Vector3D&v) 
    {
        size(SET, Size3D( m_size.x+v.x, m_size.y+v.y, m_size.z+v.z ));
    }
    
    void        ASize³::size(add_k, x_k, double v) 
    {
        size(SET, Size3D( m_size.x+v, m_size.y, m_size.z ));
    }
    
    void        ASize³::size(add_k, y_k, double v) 
    {
        size(SET, Size3D( m_size.x, m_size.y+v, m_size.z ));
    }
    
    void        ASize³::size(add_k, z_k, double v) 
    {
        size(SET, Size3D( m_size.x, m_size.y, m_size.z+v ));
    }

    void        ASize³::size(multiply_k, double v) 
    {
        size(SET, Size3D( m_size.x*v, m_size.y*v, m_size.z*v ));
    }
    
    void        ASize³::size(multiply_k, const Vector3D& v) 
    {
        size(SET, Size3D( m_size.x*v.x, m_size.y*v.y, m_size.z*v.z ));
    }
    
    void        ASize³::size(multiply_k, x_k, double v) 
    {
        size(SET, Size3D( m_size.x*v, m_size.y, m_size.z ));
    }
    
    void        ASize³::size(multiply_k, y_k, double v) 
    {
        size(SET, Size3D( m_size.x, m_size.y*v, m_size.z ));
    }
    
    void        ASize³::size(multiply_k, z_k, double v)
    {
        size(SET, Size3D( m_size.x, m_size.y, m_size.z*v ));
    }
    
    void        ASize³::on_set_size3(const SetSize³&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize³::on_set_sizeX(const SetSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize³::on_set_sizeY(const SetSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Y, cmd.y());
    }
    
    void        ASize³::on_set_sizeZ(const SetSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Z, cmd.z());
    }

    void        ASize³::on_add_size3(const AddSize³&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize³::on_add_sizeX(const AddSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize³::on_add_sizeY(const AddSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δy());
    }
    
    void        ASize³::on_add_sizeZ(const AddSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δz());
    }
    
    void        ASize³::on_multiply_size(const MultiplySize&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize³::on_multiply_size3(const MultiplySize³&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize³::on_multiply_sizeX(const MultiplySizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
    
    void        ASize³::on_multiply_sizeY(const MultiplySizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Y, cmd.δy());
    }
    
    void        ASize³::on_multiply_sizeZ(const MultiplySizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Z, cmd.δz());
    }
}
