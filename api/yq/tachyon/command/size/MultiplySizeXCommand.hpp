////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplySizeˣCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeˣCommand, SizeCommand)
    public:
        MultiplySizeˣCommand(const Header&, double);
        
        static void init_meta();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeˣCommand(const MultiplySizeˣCommand&, const Header&);
        MultiplySizeˣCommand(const Header&);
        ~MultiplySizeˣCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplySizeˣCommand(const MultiplySizeˣCommand&) = delete;
        MultiplySizeˣCommand(MultiplySizeˣCommand&&) = delete;
        MultiplySizeˣCommand& operator=(const MultiplySizeˣCommand&) = delete;
        MultiplySizeˣCommand& operator=(MultiplySizeˣCommand&&) = delete;
    };
}
