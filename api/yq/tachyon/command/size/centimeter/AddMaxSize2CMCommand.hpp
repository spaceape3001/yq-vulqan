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

    //! Instructs an object to set it's scale
    class AddMaxSize²CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize²CMCommand, SizeCommand)
    public:
        AddMaxSize²CMCommand(const Header&, const Size2CM&);
    
        const Size2CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMaxSize²CMCommand(const AddMaxSize²CMCommand&, const Header&);
        AddMaxSize²CMCommand(const Header&);
        ~AddMaxSize²CMCommand();

    private:
        Size2CM  m_Δ = ZERO;
        
        AddMaxSize²CMCommand(const AddMaxSize²CMCommand&) = delete;
        AddMaxSize²CMCommand(AddMaxSize²CMCommand&&) = delete;
        AddMaxSize²CMCommand& operator=(const AddMaxSize²CMCommand&) = delete;
        AddMaxSize²CMCommand& operator=(AddMaxSize²CMCommand&&) = delete;
    };
}
