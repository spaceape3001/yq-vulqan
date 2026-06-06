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
    class AddSize¹MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize¹MCommand, SizeCommand)
    public:
        AddSize¹MCommand(const Header&, const Size1M&);
    
        const Size1M&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddSize¹MCommand();
        AddSize¹MCommand(const AddSize¹MCommand&, const Header&);
        AddSize¹MCommand(const Header&);

    private:
        Size1M  m_Δ = ZERO;
        
        AddSize¹MCommand(const AddSize¹MCommand&) = delete;
        AddSize¹MCommand(AddSize¹MCommand&&) = delete;
        AddSize¹MCommand& operator=(const AddSize¹MCommand&) = delete;
        AddSize¹MCommand& operator=(AddSize¹MCommand&&) = delete;
    };
}
