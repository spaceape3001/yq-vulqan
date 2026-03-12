////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ASize3.hpp"
#include <yq/tachyon/command/size/AddSize3DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize3DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetSize3DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeZDCommand.hpp>
#include <yq/tachyon/event/spatial/Size3DEvent.hpp>


namespace yq::tachyon {
    ASize³::ASize³(const Param& p) : m_size(p.size)
    {
    }
    
    ASize³::ASize³(const Size3D& sz) : m_size(sz)
    {
    }

    ASize³::~ASize³()
    {
    }

    void        ASize³::size(emit_k)
    {
        send(new Size³DEvent({.source=typed()}, m_size));
    }
    
    void        ASize³::size(set_k, const Size3D& sz) 
    {
        m_size  =    sz;
        mark();
        size(EMIT);
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
    
    void        ASize³::on_set_size3(const SetSize³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize³::on_set_sizeX(const SetSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize³::on_set_sizeY(const SetSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Y, cmd.y());
    }
    
    void        ASize³::on_set_sizeZ(const SetSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Z, cmd.z());
    }

    void        ASize³::on_add_size3(const AddSize³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize³::on_add_sizeX(const AddSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize³::on_add_sizeY(const AddSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δy());
    }
    
    void        ASize³::on_add_sizeZ(const AddSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δz());
    }
    
    void        ASize³::on_multiply_size(const MultiplySizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize³::on_multiply_size3(const MultiplySize³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize³::on_multiply_sizeX(const MultiplySizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
    
    void        ASize³::on_multiply_sizeY(const MultiplySizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Y, cmd.δy());
    }
    
    void        ASize³::on_multiply_sizeZ(const MultiplySizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Z, cmd.δz());
    }
}
