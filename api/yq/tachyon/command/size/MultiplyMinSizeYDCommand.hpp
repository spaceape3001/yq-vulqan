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
    class MultiplyMinSizeʸDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeʸDCommand, SizeCommand)
    public:
        MultiplyMinSizeʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeʸDCommand(const MultiplyMinSizeʸDCommand&, const Header&);
        MultiplyMinSizeʸDCommand(const Header&);
        ~MultiplyMinSizeʸDCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplyMinSizeʸDCommand(const MultiplyMinSizeʸDCommand&) = delete;
        MultiplyMinSizeʸDCommand(MultiplyMinSizeʸDCommand&&) = delete;
        MultiplyMinSizeʸDCommand& operator=(const MultiplyMinSizeʸDCommand&) = delete;
        MultiplyMinSizeʸDCommand& operator=(MultiplyMinSizeʸDCommand&&) = delete;
    };
}
