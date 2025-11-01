////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSize³Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize³Command, SizeCommand)
    public:
        SetMaxSize³Command(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize³Command(const Header&);
        SetMaxSize³Command(const SetMaxSize³Command&, const Header&);
        ~SetMaxSize³Command();

    private:
        Size3D   m_size = ZERO;
        
        SetMaxSize³Command(const SetMaxSize³Command&) = delete;
        SetMaxSize³Command(SetMaxSize³Command&&) = delete;
        SetMaxSize³Command& operator=(const SetMaxSize³Command&) = delete;
        SetMaxSize³Command& operator=(SetMaxSize³Command&&) = delete;
    };
}
