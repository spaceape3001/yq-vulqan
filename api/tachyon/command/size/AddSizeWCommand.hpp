////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeʷCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʷCommand, SizeCommand)
    public:
        AddSizeʷCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʷCommand(const AddSizeʷCommand&, const Header&);
        AddSizeʷCommand(const Header&);
        ~AddSizeʷCommand();

    private:
        double  m_Δw = 0.0;
        
        AddSizeʷCommand(const AddSizeʷCommand&) = delete;
        AddSizeʷCommand(AddSizeʷCommand&&) = delete;
        AddSizeʷCommand& operator=(const AddSizeʷCommand&) = delete;
        AddSizeʷCommand& operator=(AddSizeʷCommand&&) = delete;
    };
}
