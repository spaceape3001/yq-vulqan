////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplySizeDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeDCommand, SizeCommand)
    public:
        MultiplySizeDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeDCommand(const MultiplySizeDCommand&, const Header&);
        ~MultiplySizeDCommand();
        MultiplySizeDCommand(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplySizeDCommand(const MultiplySizeDCommand&) = delete;
        MultiplySizeDCommand(MultiplySizeDCommand&&) = delete;
        MultiplySizeDCommand& operator=(const MultiplySizeDCommand&) = delete;
        MultiplySizeDCommand& operator=(MultiplySizeDCommand&&) = delete;
    };
}
