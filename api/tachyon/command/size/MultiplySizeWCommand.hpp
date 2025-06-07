////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplySizeʷCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeʷCommand, SizeCommand)
    public:
        MultiplySizeʷCommand(const Header&, double);
        
        static void init_info();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeʷCommand(const MultiplySizeʷCommand&, const Header&);
        MultiplySizeʷCommand(const Header&);
        ~MultiplySizeʷCommand();

    private:
        double  m_δw = 0.0;
        
        MultiplySizeʷCommand(const MultiplySizeʷCommand&) = delete;
        MultiplySizeʷCommand(MultiplySizeʷCommand&&) = delete;
        MultiplySizeʷCommand& operator=(const MultiplySizeʷCommand&) = delete;
        MultiplySizeʷCommand& operator=(MultiplySizeʷCommand&&) = delete;
    };
}
