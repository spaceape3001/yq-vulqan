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
    class MultiplySizeʸCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeʸCommand, SizeCommand)
    public:
        MultiplySizeʸCommand(const Header&, double);
        
        static void init_info();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeʸCommand(const MultiplySizeʸCommand&, const Header&);
        MultiplySizeʸCommand(const Header&);
        ~MultiplySizeʸCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplySizeʸCommand(const MultiplySizeʸCommand&) = delete;
        MultiplySizeʸCommand(MultiplySizeʸCommand&&) = delete;
        MultiplySizeʸCommand& operator=(const MultiplySizeʸCommand&) = delete;
        MultiplySizeʸCommand& operator=(MultiplySizeʸCommand&&) = delete;
    };
}
