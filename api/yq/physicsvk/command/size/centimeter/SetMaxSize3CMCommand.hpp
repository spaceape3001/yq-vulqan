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
    class SetMaxSize³CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize³CMCommand, SizeCommand)
    public:
        SetMaxSize³CMCommand(const Header&, const Size3CM&);
    
        const Size3CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize³CMCommand(const Header&);
        SetMaxSize³CMCommand(const SetMaxSize³CMCommand&, const Header&);
        ~SetMaxSize³CMCommand();

    private:
        Size3CM   m_size = ZERO;
        
        SetMaxSize³CMCommand(const SetMaxSize³CMCommand&) = delete;
        SetMaxSize³CMCommand(SetMaxSize³CMCommand&&) = delete;
        SetMaxSize³CMCommand& operator=(const SetMaxSize³CMCommand&) = delete;
        SetMaxSize³CMCommand& operator=(SetMaxSize³CMCommand&&) = delete;
    };
}
