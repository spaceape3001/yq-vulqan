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
    class AddMaxSize¹CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize¹CMCommand, SizeCommand)
    public:
        AddMaxSize¹CMCommand(const Header&, const Size1CM&);
    
        const Size1CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMaxSize¹CMCommand();
        AddMaxSize¹CMCommand(const AddMaxSize¹CMCommand&, const Header&);
        AddMaxSize¹CMCommand(const Header&);

    private:
        Size1CM  m_Δ = ZERO;
        
        AddMaxSize¹CMCommand(const AddMaxSize¹CMCommand&) = delete;
        AddMaxSize¹CMCommand(AddMaxSize¹CMCommand&&) = delete;
        AddMaxSize¹CMCommand& operator=(const AddMaxSize¹CMCommand&) = delete;
        AddMaxSize¹CMCommand& operator=(AddMaxSize¹CMCommand&&) = delete;
    };
}
