////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize¹CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize¹CMCommand, SizeCommand)
    public:
        SetSize¹CMCommand(const Header&, const Size1CM&);
    
        const Size1CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize¹CMCommand(const Header&);
        SetSize¹CMCommand(const SetSize¹CMCommand&, const Header&);
        ~SetSize¹CMCommand();

    private:
        Size1CM   m_size = ZERO;
        
        SetSize¹CMCommand(const SetSize¹CMCommand&) = delete;
        SetSize¹CMCommand(SetSize¹CMCommand&&) = delete;
        SetSize¹CMCommand& operator=(const SetSize¹CMCommand&) = delete;
        SetSize¹CMCommand& operator=(SetSize¹CMCommand&&) = delete;
    };
}
