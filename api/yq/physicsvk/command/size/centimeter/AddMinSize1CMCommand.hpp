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

    //! Instructs an object to set it's scale
    class AddMinSize¹CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize¹CMCommand, SizeCommand)
    public:
        AddMinSize¹CMCommand(const Header&, const Size1CM&);
    
        const Size1CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMinSize¹CMCommand();
        AddMinSize¹CMCommand(const AddMinSize¹CMCommand&, const Header&);
        AddMinSize¹CMCommand(const Header&);

    private:
        Size1CM  m_Δ = ZERO;
        
        AddMinSize¹CMCommand(const AddMinSize¹CMCommand&) = delete;
        AddMinSize¹CMCommand(AddMinSize¹CMCommand&&) = delete;
        AddMinSize¹CMCommand& operator=(const AddMinSize¹CMCommand&) = delete;
        AddMinSize¹CMCommand& operator=(AddMinSize¹CMCommand&&) = delete;
    };
}
