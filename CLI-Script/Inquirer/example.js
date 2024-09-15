import { select, input } from "@inquirer/prompts";
import { spawn } from "child_process";
import fs from "fs/promises";
import os from "os";

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////// Main Script
//////////////////////////////////////////////////////////////////////////////////////////

async function runScript() {
  const answer_docker = await select({
    message: "Do you want to run docker-compose?",
    choices: [
      {
        name: "yes",
        value: true,
        description: "run docker-compose",
      },
      {
        name: "no",
        value: false,
        description: "do not start any container",
      },
    ],
  });

  if (answer_docker) {
    runCommandsDetached(["echo 'Starting Docker...'", "docker-compose up --build", "echo 'Docker started'"]);
  }

  const answer_python_venv = await select({
    message: "Do you have python virtual environment already configured and up-to-date?",
    choices: [
      {
        name: "yes",
        value: true,
        description: "",
      },
      {
        name: "no",
        value: false,
        description: "",
      },
    ],
  });

  if (!answer_python_venv) {
    console.log("Please configure Python venv before running this script");
    return;
  }

  const answer_python_env = await select({
    message: "Do you have already configured the `.env` folder inside `./backend/`?",
    choices: [
      {
        name: "yes",
        value: true,
        description: "",
      },
      {
        name: "no",
        value: false,
        description: "",
      },
    ],
  });

  if (!answer_python_env) {
    try {
      await backendEnvConfig();
    } catch (err) {
      console.log(err);
      throw err;
    }
  }

  const answer_python_server_migrate = await select({
    message: "Do you want to run `python manage.py migrate` before starting the backend server?",
    choices: [
      {
        name: "yes",
        value: true,
        description: "Script will run migrate and then start the server",
      },
      {
        name: "no",
        value: false,
        description: "Script will just start the server",
      },
    ],
  });

  const DjangoCommands = ["echo 'Starting Django...'", "cd backend/"];

  if (answer_python_server_migrate) {
    DjangoCommands.push("python manage.py migrate");
  }

  DjangoCommands.push("python manage.py runserver");

  runCommandsDetached(DjangoCommands);

  const answer_frontend_env = await select({
    message: "Do you have already configured the `.env` folder inside `./Healthera/` (frontend)?",
    choices: [
      {
        name: "yes",
        value: true,
        description: "",
      },
      {
        name: "no",
        value: false,
        description: "",
      },
    ],
  });

  if (!answer_frontend_env) {
    try {
      await FrontendEnvConfig();
    } catch (err) {
      console.log(err);
      throw err;
    }
  }

  const ExpoCommands = ["echo 'Starting Expo...'", "cd Healthera/", "npm i", "npx expo start"];

  runCommandsDetached(ExpoCommands);
}

runScript();

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////// Backend Env
//////////////////////////////////////////////////////////////////////////////////////////

const backendEnvConfig = async () => {
  const answer_python_env_start = await select({
    message: "Would you like to configure the `.env` folder inside `./backend/` now?",
    choices: [
      {
        name: "yes",
        value: true,
        description: "",
      },
      {
        name: "no",
        value: false,
        description: "",
      },
    ],
  });

  if (!answer_python_env_start) {
    console.log("Skipping .env configuration...");
    console.warn("You need to configure the .env file. The server may not work properly without it.");
    return;
  }

  const GEMINI_API_KEY = await input({ message: "Enter your GEMINI_API_KEY value:" });

  await fs.writeFile("./backend/.env", `GEMINI_API_KEY=${GEMINI_API_KEY}`);
  console.log("GEMINI_API_KEY inserted successfully!");
};

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////// Frontend Env
//////////////////////////////////////////////////////////////////////////////////////////

const FrontendEnvConfig = async () => {
  const answer_frontend_env_start = await select({
    message: "Would you like to configure the `.env` folder inside `./Healthera/` now?",
    choices: [
      {
        name: "yes",
        value: true,
        description: "",
      },
      {
        name: "no",
        value: false,
        description: "",
      },
    ],
  });

  if (!answer_frontend_env_start) {
    console.log("Skipping .env configuration...");
    console.warn("You need to configure the .env file. The server may not work properly without it.");
    return;
  }

  const EXPO_PUBLIC_REST_API_SERVER = await input({
    message: "Enter your EXPO_PUBLIC_REST_API_SERVER value (e.g. `http://111.222.333.444:8000`)",
  });

  await fs.writeFile("./Healthera/.env", `EXPO_PUBLIC_REST_API_SERVER=${EXPO_PUBLIC_REST_API_SERVER}`);
  console.log("GEMINI_API_KEY inserted successfully!");
};

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////// Terminal Spawner
//////////////////////////////////////////////////////////////////////////////////////////

function runCommandsDetached(commands) {
  const platform = os.platform();
  let shell, shellArgs;

  if (platform === "win32") {
    shell = "cmd.exe";
    shellArgs = ["/c", "start", "cmd.exe", "/k"];
  } else if (platform === "darwin") {
    shell = "osascript";
    shellArgs = ["-e", 'tell app "Terminal" to do script "'];
  } else {
    // Assume Linux or other Unix-like OS
    shell = "x-terminal-emulator";
    shellArgs = ["-e", "bash", "-c"];
  }

  const commandString = commands.join(" && ");

  let spawnArgs;
  if (platform === "win32") {
    spawnArgs = [...shellArgs, commandString];
  } else if (platform === "darwin") {
    spawnArgs = [...shellArgs, `${commandString}"`];
  } else {
    spawnArgs = [...shellArgs, `${commandString}; exec bash`];
  }

  const terminal = spawn(shell, spawnArgs, {
    detached: true,
    stdio: "ignore",
  });

  terminal.unref();

  console.log(`Detached process started with PID ${terminal.pid}`);
}
