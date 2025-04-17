const otpInputs = document.querySelectorAll('.otp-input');
const verifyBtn = document.getElementById('verify-otp');

otpInputs.forEach((input, index) => {
    input.addEventListener("input", () => {
        const nextInput = otpInputs[index + 1];
        if (input.value && nextInput) {
            nextInput.focus();
        }
    });

    // TO DELETE USING BACKSPACE
    input.addEventListener("keydown", (e) => {
        if (e.key === "Backspace") {
            const prevInput = otpInputs[index - 1];
            
            if (prevInput && !input.value)  {
                prevInput.value = "";
                prevInput.focus();
            }
        }
    })
})

verifyBtn.addEventListener("click", () => {
    const otpValue = Array.from(otpInputs).map((input) => input.value).join("");
    console.log("OTP Value :", otpValue);
})