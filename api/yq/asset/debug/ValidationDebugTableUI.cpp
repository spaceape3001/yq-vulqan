////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ValidationDebugTableUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/im/KVTable.hpp>
#include <yq/tachyon/im/stackback.hpp>
#include <yq/tachyon/im/text.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/tachyon/vulkan/ViDebugTrace.hpp>
#include <yq/text/format.hpp>
#include "imgui_internal.h"

YQ_OBJECT_IMPLEMENT(yq::tachyon::ValidationDebugTableUI)

namespace yq::tachyon {
    ValidationDebugTableUI::ValidationDebugTableUI(UIFlags flags) : UIElement(flags)
    {
    }
    
    ValidationDebugTableUI::ValidationDebugTableUI(const ValidationDebugTableUI& cp) :
        UIElement(cp)
    {
    }
    
    ValidationDebugTableUI::~ValidationDebugTableUI()
    {
    }

    void ValidationDebugTableUI::add(const ViDebugTraceCPtr& evt)
    {
        if(!evt)
            return ;
        m_data.push_back(evt);
    }

    ValidationDebugTableUI* ValidationDebugTableUI::clone() const
    {
        return new ValidationDebugTableUI(*this);
    }
    
    #if 0
    template <typename Pred>
    void      guard(Pred&& pred)
    {
        auto &id_stack = ImGui::GetCurrentWindow()->IDStack;
        const auto outer_table_instance_id  = id_stack.back();
        id_stack.pop_back();
        pred();
        id_stack.push_back(outer_table_instance_id);
    }
    #endif

    void ValidationDebugTableUI::render()
    {
        static constexpr const char* szTable    = "Validation";
        static constexpr const int   nColumns    = 4;
        static constexpr const ImGuiTableFlags  kFlags  = ImGuiTableFlags_SizingFixedFit;
    
        if(!ImGui::BeginTable(szTable, nColumns, kFlags))
            return ;

        ImGui::TableSetupColumn("ID");
        ImGui::TableSetupColumn("Time");
        ImGui::TableSetupColumn("Code");
        ImGui::TableSetupColumn("Message");
        ImGui::TableHeadersRow();
            
        for(auto& d : m_data){
            bool    fExpand = false;
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                std::string tt  = to_string(d->id);
                fExpand = ImGui::TreeNodeEx(tt.c_str(), ImGuiTreeNodeFlags_NoTreePushOnOpen);
            }
            
            if(ImGui::TableNextColumn()){
                im::text(d->time);
            }
            
            if(ImGui::TableNextColumn()){
                im::text(fmt_hex(d->msgIdNumber));
            }
            
            if(ImGui::TableNextColumn()){
                im::text(d->message);
            }
            
            if(fExpand){
                ImGui::EndTable();
                ImGui::Indent();
                //im::stackback(1, [&](){
                    render(*d);
                //});
                ImGui::Unindent();
                ImGui::BeginTable(szTable, nColumns, kFlags);
            }
        }

        ImGui::EndTable();
    }
    
    namespace {
        std::string   tty(VkDebugUtilsMessageSeverityFlagBitsEXT sevs)
        {
            std::string     ret;
            if(sevs & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT)
                ret += "ERROR ";
            if(sevs & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
                ret += "WARNING ";
            if(sevs & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT)
                ret += "INFO ";
            if(sevs & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT)
                ret += "VERBOSE ";
            return ret;
        }

        std::string   tty(VkDebugUtilsMessageTypeFlagsEXT sevs)
        {
            std::string     ret;
            if(sevs & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT)
                ret += "GENERAL ";
            if(sevs & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT)
                ret += "VALIDATION ";
            if(sevs & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT)
                ret += "PERFORMANCE ";
            if(sevs & VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT)
                ret += "BINDING ";
            return ret;
        }
        
        std::string tty(VkObjectType type)
        {
            switch(type){
            case VK_OBJECT_TYPE_UNKNOWN:
                return "Unknown";
            case VK_OBJECT_TYPE_INSTANCE:
                return "Instance";
            case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
                return "Physical Device";
            case VK_OBJECT_TYPE_DEVICE:
                return "Device";
            case VK_OBJECT_TYPE_QUEUE:
                return "Queue";
            case VK_OBJECT_TYPE_SEMAPHORE:
                return "Semaphore";
            case VK_OBJECT_TYPE_COMMAND_BUFFER:
                return "Command Buffer";
            case VK_OBJECT_TYPE_FENCE:
                return "Fence";
            case VK_OBJECT_TYPE_DEVICE_MEMORY:
                return "Device Memory";
            case VK_OBJECT_TYPE_BUFFER:
                return "Buffer";
            case VK_OBJECT_TYPE_IMAGE:
                return "Image";
            case VK_OBJECT_TYPE_EVENT:
                return "Event";
            case VK_OBJECT_TYPE_QUERY_POOL:
                return "Query Pool";
            case VK_OBJECT_TYPE_BUFFER_VIEW:
                return "Buffer View";
            case VK_OBJECT_TYPE_IMAGE_VIEW:
                return "Image View";
            case VK_OBJECT_TYPE_SHADER_MODULE:
                return "Shader Module";
            case VK_OBJECT_TYPE_PIPELINE_CACHE:
                return "Pipeline Cache";
            case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
                return "Pipeline Layout";
            case VK_OBJECT_TYPE_RENDER_PASS:
                return "Render Pass";
            case VK_OBJECT_TYPE_PIPELINE:
                return "Pipeline";
            case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
                return "Descriptor Set Layout";
            case VK_OBJECT_TYPE_SAMPLER:
                return "Sampler";
            case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
                return "Descriptor Pool";
            case VK_OBJECT_TYPE_DESCRIPTOR_SET:
                return "Descriptor Set";
            case VK_OBJECT_TYPE_FRAMEBUFFER:
                return "Framebuffer";
            case VK_OBJECT_TYPE_COMMAND_POOL:
                return "Command Pool";
            case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
                return "Descriptor Update Template";
            case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
                return "Sampler YCBCR Conversion";
            case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT:
                return "Private Data Slot";
            case VK_OBJECT_TYPE_SURFACE_KHR:
                return "Surface";
            case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
                return "Swapchain";
            case VK_OBJECT_TYPE_DISPLAY_KHR:
                return "Display";
            case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
                return "Display Mode";
            case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
                return "Debug Report Callback";
            case VK_OBJECT_TYPE_VIDEO_SESSION_KHR:
                return "Video Session";
            case VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR:
                return "Video Session Parameters";
            case VK_OBJECT_TYPE_CU_MODULE_NVX:
                return "CU Module";
            case VK_OBJECT_TYPE_CU_FUNCTION_NVX:
                return "CU Function";
            case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
                return "Debug Utils Messenger";
            case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
                return "Acceleration Structure (KHR)";
            case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
                return "Validation Cache";
            case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
                return "Acceleration Structure (nVidia)";
            case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
                return "Performance Configuration";
            case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
                return "Deferred Operation";
            case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
                return "Indirect Commands Layout";
        #ifdef VK_ENABLE_BETA_EXTENSIONS
            case VK_OBJECT_TYPE_CUDA_MODULE_NV:
                return "Cuda Module";
            case VK_OBJECT_TYPE_CUDA_FUNCTION_NV:
                return "Cuda Function";
        #endif
            case VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA:
                return "Buffer Collection";
            case VK_OBJECT_TYPE_MICROMAP_EXT:
                return "Micromap";
            case VK_OBJECT_TYPE_TENSOR_ARM:
                return "Tensor";
            case VK_OBJECT_TYPE_TENSOR_VIEW_ARM:
                return "Tensor View";
            case VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV:
                return "Optical Flow Session";
            case VK_OBJECT_TYPE_SHADER_EXT:
                return "Shader";
            case VK_OBJECT_TYPE_PIPELINE_BINARY_KHR:
                return "Pipeline Binary";
            case VK_OBJECT_TYPE_DATA_GRAPH_PIPELINE_SESSION_ARM:
                return "Data Graph Pipeline Session";
            case VK_OBJECT_TYPE_EXTERNAL_COMPUTE_QUEUE_NV:
                return "Extenral Compute Queue";
            case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT:
                return "Indirect Commands Layout";
            case VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT:
                return "Indirect Execution";
            default:
                return std::format("Undefined {}", (int) type);
            }
        }
    }
    
    void ValidationDebugTableUI::render(const ViDebugTrace& dbg)
    {
        ImGui::PushID((void*) dbg.id);
        {
            im::KVTable kv;
            kv("Flags")         << fmt_hex(dbg.flags);
            kv("Msg ID")        << fmt_hex(dbg.msgIdNumber);
            kv("Msg Name")      << dbg.msgIdName;
            kv("Severity")      << tty(dbg.severity);
            kv("Tachyon")       << dbg.tachyon.id;
            kv("Thread")        << dbg.thread.id;
            kv("Type")          << tty(dbg.types);
        }
        
        if(ImGui::TreeNode("Command Buffers")){
            if(ImGui::BeginTable("CommandBuffers",2,ImGuiTableFlags_SizingFixedFit)){
                int cnt = 0;
                for(auto& l : dbg.cmdbufs){
                    ImGui::TableNextRow();
                    if(ImGui::TableNextColumn())
                        im::text(++cnt);
                    if(ImGui::TableNextColumn())
                        im::text(l.name);
                }
                ImGui::EndTable();
            }
            
            ImGui::TreePop();
        }
        
        if(ImGui::TreeNode("Objects")){
            if(ImGui::BeginTable("Objects",4,ImGuiTableFlags_SizingFixedFit)){
                int cnt = 0;
                for(auto& l : dbg.objects){
                    ImGui::TableNextRow();
                    if(ImGui::TableNextColumn())
                        im::text(++cnt);
                    if(ImGui::TableNextColumn())
                        im::text(tty(l.type));
                    if(ImGui::TableNextColumn())
                        im::text(fmt_hex(l.handle));
                    if(ImGui::TableNextColumn())
                        im::text(l.name);
                }
                ImGui::EndTable();
            }
            
            ImGui::TreePop();
        }

        if(ImGui::TreeNode("Queues")){
            if(ImGui::BeginTable("Queues",2,ImGuiTableFlags_SizingFixedFit)){
                int cnt = 0;
                for(auto& l : dbg.queues){
                    ImGui::TableNextRow();
                    if(ImGui::TableNextColumn())
                        im::text(++cnt);
                    if(ImGui::TableNextColumn())
                        im::text(l.name);
                }
                ImGui::EndTable();
            }
            
            ImGui::TreePop();
        }

        if(ImGui::TreeNode("Stack")){
            if(ImGui::BeginTable("StackTrace",2,ImGuiTableFlags_SizingFixedFit)){
                ImGui::TableSetupColumn("File");
                ImGui::TableSetupColumn("Line");
                ImGui::TableHeadersRow();
                
                for(auto& t : dbg.trace){
                    ImGui::TableNextRow();
                    if(ImGui::TableNextColumn())
                        im::text(t.file);
                    if(ImGui::TableNextColumn())
                        im::text(t.line);
                }
            
                ImGui::EndTable();
            }
            
            ImGui::TreePop();
        }

        ImGui::PopID();
    }

    void ValidationDebugTableUI::init_meta()
    {
        auto w = writer<ValidationDebugTableUI>();
        w.description("Validation Debug Table");
    }
}

