Get-ChildItem | ForEach-Object {
    if (-not $_.PSIsContainer) {
        $filename = $_.Name
        Get-Content $_.FullName | ForEach-Object -Begin {$i = 1} {
            if ($i % 2 -eq 0) {
                Write-Host "$filename: $_"
            }
            $i++
        }
    }
}