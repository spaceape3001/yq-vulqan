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
    class AddSize¹CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize¹CMCommand, SizeCommand)
    public:
        AddSize¹CMCommand(const Header&, const Size1CM&);
    
        const Size1CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddSize¹CMCommand();
        AddSize¹CMCommand(const AddSize¹CMCommand&, const Header&);
        AddSize¹CMCommand(const Header&);

    private:
        Size1CM  m_Δ = ZERO;
        
        AddSize¹CMCommand(const AddSize¹CMCommand&) = delete;
        AddSize¹CMCommand(AddSize¹CMCommand&&) = delete;
        AddSize¹CMCommand& operator=(const AddSize¹CMCommand&) = delete;
        AddSize¹CMCommand& operator=(AddSize¹CMCommand&&) = delete;
    };
}
