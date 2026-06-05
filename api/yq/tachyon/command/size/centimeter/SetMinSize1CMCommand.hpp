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
    class SetMinSize¹CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize¹CMCommand, SizeCommand)
    public:
        SetMinSize¹CMCommand(const Header&, const Size1CM&);
    
        const Size1CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize¹CMCommand(const Header&);
        SetMinSize¹CMCommand(const SetMinSize¹CMCommand&, const Header&);
        ~SetMinSize¹CMCommand();

    private:
        Size1CM   m_size = ZERO;
        
        SetMinSize¹CMCommand(const SetMinSize¹CMCommand&) = delete;
        SetMinSize¹CMCommand(SetMinSize¹CMCommand&&) = delete;
        SetMinSize¹CMCommand& operator=(const SetMinSize¹CMCommand&) = delete;
        SetMinSize¹CMCommand& operator=(SetMinSize¹CMCommand&&) = delete;
    };
}
