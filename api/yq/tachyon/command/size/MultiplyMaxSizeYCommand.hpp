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
    class MultiplyMaxSizeʸCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeʸCommand, SizeCommand)
    public:
        MultiplyMaxSizeʸCommand(const Header&, double);
        
        static void init_meta();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeʸCommand(const MultiplyMaxSizeʸCommand&, const Header&);
        MultiplyMaxSizeʸCommand(const Header&);
        ~MultiplyMaxSizeʸCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplyMaxSizeʸCommand(const MultiplyMaxSizeʸCommand&) = delete;
        MultiplyMaxSizeʸCommand(MultiplyMaxSizeʸCommand&&) = delete;
        MultiplyMaxSizeʸCommand& operator=(const MultiplyMaxSizeʸCommand&) = delete;
        MultiplyMaxSizeʸCommand& operator=(MultiplyMaxSizeʸCommand&&) = delete;
    };
}
