////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSize³DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize³DCommand, SizeCommand)
    public:
        SetMaxSize³DCommand(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize³DCommand(const Header&);
        SetMaxSize³DCommand(const SetMaxSize³DCommand&, const Header&);
        ~SetMaxSize³DCommand();

    private:
        Size3D   m_size = ZERO;
        
        SetMaxSize³DCommand(const SetMaxSize³DCommand&) = delete;
        SetMaxSize³DCommand(SetMaxSize³DCommand&&) = delete;
        SetMaxSize³DCommand& operator=(const SetMaxSize³DCommand&) = delete;
        SetMaxSize³DCommand& operator=(SetMaxSize³DCommand&&) = delete;
    };
}
