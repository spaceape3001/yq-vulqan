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
    class AddMaxSize¹MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize¹MCommand, SizeCommand)
    public:
        AddMaxSize¹MCommand(const Header&, const Size1M&);
    
        const Size1M&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMaxSize¹MCommand();
        AddMaxSize¹MCommand(const AddMaxSize¹MCommand&, const Header&);
        AddMaxSize¹MCommand(const Header&);

    private:
        Size1M  m_Δ = ZERO;
        
        AddMaxSize¹MCommand(const AddMaxSize¹MCommand&) = delete;
        AddMaxSize¹MCommand(AddMaxSize¹MCommand&&) = delete;
        AddMaxSize¹MCommand& operator=(const AddMaxSize¹MCommand&) = delete;
        AddMaxSize¹MCommand& operator=(AddMaxSize¹MCommand&&) = delete;
    };
}
