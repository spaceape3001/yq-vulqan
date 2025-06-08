////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetVertexPosition³Command : public PositionCommand {
        YQ_OBJECT_DECLARE(SetVertexPosition³Command, PositionCommand)
    public:
        SetVertexPosition³Command(const Header&, unsigned, const Vector3D&);
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        unsigned vertex() const { return m_vertex; }

    protected:
        ~SetVertexPosition³Command();
        SetVertexPosition³Command(const SetVertexPosition³Command&, const Header&);
    
    private:
        Vector3D    m_position;
        unsigned    m_vertex;
        
        SetVertexPosition³Command(const SetVertexPosition³Command&) = delete;
        SetVertexPosition³Command(SetVertexPosition³Command&&) = delete;
        SetVertexPosition³Command& operator=(const SetVertexPosition³Command&) = delete;
        SetVertexPosition³Command& operator=(SetVertexPosition³Command&&) = delete;
    };
}
