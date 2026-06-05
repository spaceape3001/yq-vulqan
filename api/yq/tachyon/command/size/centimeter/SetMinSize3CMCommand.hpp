////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize³CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize³CMCommand, SizeCommand)
    public:
        SetMinSize³CMCommand(const Header&, const Size3CM&);
    
        const Size3CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize³CMCommand(const Header&);
        SetMinSize³CMCommand(const SetMinSize³CMCommand&, const Header&);
        ~SetMinSize³CMCommand();

    private:
        Size3CM   m_size = ZERO;
        
        SetMinSize³CMCommand(const SetMinSize³CMCommand&) = delete;
        SetMinSize³CMCommand(SetMinSize³CMCommand&&) = delete;
        SetMinSize³CMCommand& operator=(const SetMinSize³CMCommand&) = delete;
        SetMinSize³CMCommand& operator=(SetMinSize³CMCommand&&) = delete;
    };
}
