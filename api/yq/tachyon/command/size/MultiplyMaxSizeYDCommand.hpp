////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplyMaxSizeʸDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeʸDCommand, SizeCommand)
    public:
        MultiplyMaxSizeʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeʸDCommand(const MultiplyMaxSizeʸDCommand&, const Header&);
        MultiplyMaxSizeʸDCommand(const Header&);
        ~MultiplyMaxSizeʸDCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplyMaxSizeʸDCommand(const MultiplyMaxSizeʸDCommand&) = delete;
        MultiplyMaxSizeʸDCommand(MultiplyMaxSizeʸDCommand&&) = delete;
        MultiplyMaxSizeʸDCommand& operator=(const MultiplyMaxSizeʸDCommand&) = delete;
        MultiplyMaxSizeʸDCommand& operator=(MultiplyMaxSizeʸDCommand&&) = delete;
    };
}
