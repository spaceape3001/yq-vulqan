////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize¹DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize¹DCommand, SizeCommand)
    public:
        AddMaxSize¹DCommand(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMaxSize¹DCommand();
        AddMaxSize¹DCommand(const AddMaxSize¹DCommand&, const Header&);
        AddMaxSize¹DCommand(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddMaxSize¹DCommand(const AddMaxSize¹DCommand&) = delete;
        AddMaxSize¹DCommand(AddMaxSize¹DCommand&&) = delete;
        AddMaxSize¹DCommand& operator=(const AddMaxSize¹DCommand&) = delete;
        AddMaxSize¹DCommand& operator=(AddMaxSize¹DCommand&&) = delete;
    };
}
