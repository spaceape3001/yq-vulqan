////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMinSizeʷCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʷCommand, SizeCommand)
    public:
        AddMinSizeʷCommand(const Header&, double);
        
        static void init_info();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʷCommand(const AddMinSizeʷCommand&, const Header&);
        AddMinSizeʷCommand(const Header&);
        ~AddMinSizeʷCommand();

    private:
        double  m_Δw = 0.0;
        
        AddMinSizeʷCommand(const AddMinSizeʷCommand&) = delete;
        AddMinSizeʷCommand(AddMinSizeʷCommand&&) = delete;
        AddMinSizeʷCommand& operator=(const AddMinSizeʷCommand&) = delete;
        AddMinSizeʷCommand& operator=(AddMinSizeʷCommand&&) = delete;
    };
}
