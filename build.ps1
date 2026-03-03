#!/usr/bin/env pwsh

$ErrorActionPreference = "Stop"

$CWD = (Get-Location).Path
$ScriptName = [System.IO.Path]::GetFileName($MyInvocation.MyCommand.Path)

function die {
	param(
		[string]$msg = "Script terminated!"
	)

	Write-Host "${ScriptName}: ERR: ${msg}" -ForegroundColor DarkRed
	exit 1
}
