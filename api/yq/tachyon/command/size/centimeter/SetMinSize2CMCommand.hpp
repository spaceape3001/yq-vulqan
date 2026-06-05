////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize²CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize²CMCommand, SizeCommand)
    public:
        SetMinSize²CMCommand(const Header&, const Size2CM&);
    
        const Size2CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize²CMCommand(const Header&);
        SetMinSize²CMCommand(const SetMinSize²CMCommand&, const Header&);
        ~SetMinSize²CMCommand();

    private:
        Size2CM   m_size = ZERO;
        
        SetMinSize²CMCommand(const SetMinSize²CMCommand&) = delete;
        SetMinSize²CMCommand(SetMinSize²CMCommand&&) = delete;
        SetMinSize²CMCommand& operator=(const SetMinSize²CMCommand&) = delete;
        SetMinSize²CMCommand& operator=(SetMinSize²CMCommand&&) = delete;
    };
}
