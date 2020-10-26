// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.
//
// Module Name:
// - Jumplist.h
//
// Abstract:
// - The Jumplist is the menu that pops up when right clicking a pinned
// item in the taskbar. This class handles updating the Terminal's jumplist
// using the Terminal's settings.
//

#pragma once

#include "CascadiaSettings.h"

struct IObjectCollection;
struct IShellLinkW;

class Jumplist
{
public:
    static winrt::fire_and_forget UpdateJumplist(const winrt::TerminalApp::CascadiaSettings& settings) noexcept;

private:
    [[nodiscard]] static HRESULT _updateProfiles(IObjectCollection* jumplistItems, winrt::Windows::Foundation::Collections::IVectorView<winrt::TerminalApp::Profile> profiles) noexcept;
    [[nodiscard]] static HRESULT _createShellLink(const std::wstring_view name, const std::wstring_view path, const std::wstring_view args, IShellLinkW** shLink) noexcept;
};