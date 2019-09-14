param(
    [string]$triplet = 'x86-windows',
    [switch]$noConfirm = $false
)

# This file is created after running 'vcpkg integrate install' and contains the path to the root
$vcpkg_path_file = "${env:LOCALAPPDATA}/vcpkg/vcpkg.path.txt"
if (-not (Test-Path $vcpkg_path_file)) {
    throw "No vcpkg installation found. Have you run 'vcpkg integrate install'?`nSee https://github.com/Microsoft/vcpkg for installation instructions."
}

$vcpkg = "$(Get-Content "${env:LOCALAPPDATA}/vcpkg/vcpkg.path.txt")/vcpkg.exe"
if ((Get-Command $vcpkg -ErrorAction SilentlyContinue) -eq $null) {
    throw "No vcpkg found at '$vcpkg'. Do you need to re-run 'vcpkg integrate install'?`nSee https://github.com/Microsoft/vcpkg for installation instructions."
}

$vcpkgTripletCommand = "$vcpkg help triplet"
$availableTriplets = @(Invoke-Expression $vcpkgTripletCommand) | Select-Object -Skip 1
if (-not $availableTriplets.Trim().Contains($triplet)) {
    throw "Unknown triplet '$triplet'. Run '$vcpkgTripletCommand' to see available triplets."
}

$dependencies = "boost-date-time","boost-filesystem","boost-format","boost-locale","boost-system","curl","freetype","glew","libogg","libvorbis","openal-soft","sdl2","sdl2-image"
$installCommand = "$vcpkg install --triplet $triplet $($dependencies -join ' ')"

if (-not $noConfirm) {
    $confirm = Read-Host "Run '$installCommand'? [Y/n]"
    if (-not [string]::IsNullOrEmpty($confirm) -and $confirm -match "[ nN]") {
        Write-Host "Fine be that way 😢"
        exit 0
    }
}

Invoke-Expression $installCommand