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
    class SetSize²CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize²CMCommand, SizeCommand)
    public:
        SetSize²CMCommand(const Header&, const Size2CM&);
    
        const Size2CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize²CMCommand(const Header&);
        SetSize²CMCommand(const SetSize²CMCommand&, const Header&);
        ~SetSize²CMCommand();

    private:
        Size2CM   m_size = ZERO;
        
        SetSize²CMCommand(const SetSize²CMCommand&) = delete;
        SetSize²CMCommand(SetSize²CMCommand&&) = delete;
        SetSize²CMCommand& operator=(const SetSize²CMCommand&) = delete;
        SetSize²CMCommand& operator=(SetSize²CMCommand&&) = delete;
    };
}
