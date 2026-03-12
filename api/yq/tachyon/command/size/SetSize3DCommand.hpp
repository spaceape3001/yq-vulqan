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
    class SetSize³DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize³DCommand, SizeCommand)
    public:
        SetSize³DCommand(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize³DCommand(const Header&);
        SetSize³DCommand(const SetSize³DCommand&, const Header&);
        ~SetSize³DCommand();

    private:
        Size3D   m_size = ZERO;
        
        SetSize³DCommand(const SetSize³DCommand&) = delete;
        SetSize³DCommand(SetSize³DCommand&&) = delete;
        SetSize³DCommand& operator=(const SetSize³DCommand&) = delete;
        SetSize³DCommand& operator=(SetSize³DCommand&&) = delete;
    };
}
