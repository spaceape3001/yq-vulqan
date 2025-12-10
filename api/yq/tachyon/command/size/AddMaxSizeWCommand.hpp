////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMaxSizeʷCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʷCommand, SizeCommand)
    public:
        AddMaxSizeʷCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʷCommand(const AddMaxSizeʷCommand&, const Header&);
        AddMaxSizeʷCommand(const Header&);
        ~AddMaxSizeʷCommand();

    private:
        double  m_Δw = 0.0;
        
        AddMaxSizeʷCommand(const AddMaxSizeʷCommand&) = delete;
        AddMaxSizeʷCommand(AddMaxSizeʷCommand&&) = delete;
        AddMaxSizeʷCommand& operator=(const AddMaxSizeʷCommand&) = delete;
        AddMaxSizeʷCommand& operator=(AddMaxSizeʷCommand&&) = delete;
    };
}
