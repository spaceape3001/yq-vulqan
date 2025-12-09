////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/command/Circular3Command.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³OriginCommand : public Circular³Command {
        YQ_OBJECT_DECLARE(Circular³OriginCommand, Circular³Command)
    public:
    
        static void init_meta();
        Circular³OriginCommand(const Header&, const Vector3D&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Vector3D&    origin() const { return m_origin; }
        
    protected:
        Circular³OriginCommand(const Circular³OriginCommand&, const Header&);
        ~Circular³OriginCommand();
        
    private:
        Vector3D    m_origin;
    
        Circular³OriginCommand(const Circular³OriginCommand&) = delete;
        Circular³OriginCommand(Circular³OriginCommand&&) = delete;
        Circular³OriginCommand& operator=(const Circular³OriginCommand&) = delete;
        Circular³OriginCommand& operator=(Circular³OriginCommand&&) = delete;
    };
}
