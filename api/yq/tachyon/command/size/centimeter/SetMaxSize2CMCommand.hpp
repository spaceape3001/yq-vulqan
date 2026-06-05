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
    class SetMaxSize²CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize²CMCommand, SizeCommand)
    public:
        SetMaxSize²CMCommand(const Header&, const Size2CM&);
    
        const Size2CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize²CMCommand(const Header&);
        SetMaxSize²CMCommand(const SetMaxSize²CMCommand&, const Header&);
        ~SetMaxSize²CMCommand();

    private:
        Size2CM   m_size = ZERO;
        
        SetMaxSize²CMCommand(const SetMaxSize²CMCommand&) = delete;
        SetMaxSize²CMCommand(SetMaxSize²CMCommand&&) = delete;
        SetMaxSize²CMCommand& operator=(const SetMaxSize²CMCommand&) = delete;
        SetMaxSize²CMCommand& operator=(SetMaxSize²CMCommand&&) = delete;
    };
}
