////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplyMinSizeʸCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeʸCommand, SizeCommand)
    public:
        MultiplyMinSizeʸCommand(const Header&, double);
        
        static void init_info();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeʸCommand(const MultiplyMinSizeʸCommand&, const Header&);
        MultiplyMinSizeʸCommand(const Header&);
        ~MultiplyMinSizeʸCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplyMinSizeʸCommand(const MultiplyMinSizeʸCommand&) = delete;
        MultiplyMinSizeʸCommand(MultiplyMinSizeʸCommand&&) = delete;
        MultiplyMinSizeʸCommand& operator=(const MultiplyMinSizeʸCommand&) = delete;
        MultiplyMinSizeʸCommand& operator=(MultiplyMinSizeʸCommand&&) = delete;
    };
}
