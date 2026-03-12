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
    class MultiplySizeʸDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeʸDCommand, SizeCommand)
    public:
        MultiplySizeʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeʸDCommand(const MultiplySizeʸDCommand&, const Header&);
        MultiplySizeʸDCommand(const Header&);
        ~MultiplySizeʸDCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplySizeʸDCommand(const MultiplySizeʸDCommand&) = delete;
        MultiplySizeʸDCommand(MultiplySizeʸDCommand&&) = delete;
        MultiplySizeʸDCommand& operator=(const MultiplySizeʸDCommand&) = delete;
        MultiplySizeʸDCommand& operator=(MultiplySizeʸDCommand&&) = delete;
    };
}
